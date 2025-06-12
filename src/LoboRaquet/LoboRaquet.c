#include "Raquet.h"

SDL_Texture * LoboRaquet_LoadIMG(char * filename) {
    SDL_Surface *temp_surf;
    SDL_Texture *tex;
    temp_surf = IMG_Load(Raquet_AbsoluteToAsset(filename)); // load the png onto a temporary surface
    tex = SDL_CreateTextureFromSurface(Raquet_Renderer, temp_surf); // create a texture from said surface
    SDL_FreeSurface(temp_surf); // free the mf from meory
    return tex;
}

void LoboRaquet_PlaceIMG(SDL_Texture * tex, int x, int y) {
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width,
        height
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
}

void LoboRaquet_PlaceIMG_ext(SDL_Texture * tex, int x, int y, int xsize, int ysize, double angle, Raquet_Point center, SDL_RendererFlip flip) {
    SDL_Rect dstrect = {
        x - center.x,
        y - center.y,
        xsize,
        ysize
    };
    SDL_RenderCopyEx(Raquet_Renderer, tex, NULL, & dstrect, angle, & center, flip);
}

SDL_Texture *LoboRaquet_GetStringTexture(TTF_Font *font, char *string, int r, int g, int b, int alpha, Uint32 wraplength) {
    SDL_Surface *temp_surf;
    SDL_Texture *tex;
    SDL_Color color={ r, g, b, alpha };
    temp_surf = TTF_RenderText_Blended_Wrapped(font, string, color, wraplength);
    tex = SDL_CreateTextureFromSurface(Raquet_Renderer, temp_surf);
    SDL_FreeSurface(temp_surf);

    return tex;
}

int LoboRaquet_GetTextWidth(TTF_Font *font, char *string) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, 255, 255, 255, 255, 2147483647);
    int width;
    SDL_QueryTexture(tex, NULL, NULL, &width, NULL);
    SDL_DestroyTexture(tex);
    return width;
}

int LoboRaquet_GetTextHeight(TTF_Font *font, char *string) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, 255, 255, 255, 255, 2147483647);
    int height;
    SDL_QueryTexture(tex, NULL, NULL, NULL, &height);
    SDL_DestroyTexture(tex);
    return height;
}

void LoboRaquet_PlaceText(TTF_Font *font, char *string, int x, int y) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, 255, 255, 255, 255, 2147483647);
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width,
        height
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
    SDL_DestroyTexture(tex);
}

void LoboRaquet_PlaceText_ext(TTF_Font *font, char *string, int x, int y, int xscale, int yscale, SDL_Color color, Uint32 wrapLength) {
    SDL_Texture *tex = LoboRaquet_GetStringTexture(font, string, color.r, color.g, color.b, color.a, wrapLength);
    int width;
    int height;
    SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_Rect dstrect = {
        x,
        y,
        width * xscale,
        height * yscale
    };
    SDL_RenderCopy(Raquet_Renderer, tex, NULL, & dstrect);
    SDL_DestroyTexture(tex);
}

TTF_Font *LoboRaquet_LoadFont(char *filename, int size) {
    return TTF_OpenFont(Raquet_AbsoluteToAsset(filename), size);
}

// Maximum size in bytes that will be read when receiving data over TCP.
#define MAX_NET_BYTES 1024

TCPsocket LoboRaquet_NetClient_ConnectTCP(IPaddress *ip, const char *host, Uint16 port) {
    if (SDLNet_ResolveHost(ip, host, port) < 0) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(1);
    }

    TCPsocket sock = SDLNet_TCP_Open(ip);
    if (!sock) {
        printf("LoboRaquet_NetClient_ConnectTCP: %s\n", SDLNet_GetError());
        exit(2);
    }

    return sock;
}

TCPsocket LoboRaquet_NetServer_CreateSocketTCP(IPaddress *ip, Uint16 port) {
    if(SDLNet_ResolveHost(ip,NULL,port) < 0) {
        printf("SDLNet_ResolveHost: %s\n", SDLNet_GetError());
        exit(1);
    }
    
    TCPsocket sock = SDLNet_TCP_Open(ip);
    if (!sock) {
        printf("LoboRaquet_NetServer_CreateSocketTCP: %s\n", SDLNet_GetError());
        exit(2);
    }

    return sock;
}

TCPsocket LoboRaquet_NetServer_AcceptSocketTCP(TCPsocket serverSock) {
    TCPsocket new;

    new = SDLNet_TCP_Accept(serverSock);
    if (!new) {
        printf("oboRaquet_NetServer_AcceptSocketTCP: %s\n", SDLNet_GetError());
    }

    return new;
}

IPaddress LoboRaquet_Net_GetSocketAddress(TCPsocket sock) {
    IPaddress *ip;
    
    ip = SDLNet_TCP_GetPeerAddress(sock);
    if (!ip) {
        printf("LoboRaquet_Net_GetSocketAddress: %s\n", SDLNet_GetError());
        printf("This may be a server socket.\n");
    }

    return *ip;
}

int LoboRaquet_Net_SendTCPText(TCPsocket sock, const char *data) {
    int size, result;
    size = strlen(data);
    result = SDLNet_TCP_Send(sock, data, size);
    if (result < size) {
        printf("LoboRaquet_Net_SendTCP: %s\n", SDLNet_GetError());
        return 0;
    }
    return 1;
}

int LoboRaquet_Net_ReceiveTCPText(TCPsocket sock) {
    int result;
    int success = 1;
    char msg[MAX_NET_BYTES];

    result = SDLNet_TCP_Recv(sock, msg, MAX_NET_BYTES);
    if (result < 1) {
        // an error probably/might've occured but usually you can just ignore it.
        // however it may be good to disconnect the sock because its probably invalid now LMAO
        success = 0;
    }
    printf("Received: \"%s\"\n", msg);
    return success;
}

void LoboRaquet_Net_CloseSocketTCP(TCPsocket sock) {
    SDLNet_TCP_Close(sock);
}