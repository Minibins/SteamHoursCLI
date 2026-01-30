#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>

#include "lib/steam_api.h"

static volatile sig_atomic_t g_running = 1;

static void on_sigint(int sig) {
    (void)sig;
    g_running = 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <app_id>\nExample: %s 730\n", argv[0], argv[0]);
        return 2;
    }

    uint32_t app_id = (uint32_t)strtoul(argv[1], NULL, 10);
    if (app_id == 0) {
        fprintf(stderr, "Invalid app_id.\n");
        return 2;
    }

    char appid_str[32];
    snprintf(appid_str, sizeof(appid_str), "%u", app_id);
    setenv("SteamAppId", appid_str, 1);
    setenv("SteamGameId", appid_str, 1);

    if (!SteamAPI_Init()) {
        fprintf(stderr, "SteamAPI_Init failed. Is Steam running and logged in?\n");
        return 1;
    }

    printf("SteamAPI initialized. Now idling as AppID %u.\n", app_id);
    printf("Press Ctrl+C to stop.\n");

    signal(SIGINT, on_sigint);
    signal(SIGTERM, on_sigint);

    while (g_running) {
        usleep(500 * 1000);
    }

    printf("Stopped.\n");
    return 0;
}
