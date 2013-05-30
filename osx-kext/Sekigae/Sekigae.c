//
//  Sekigae.c
//  Sekigae
//
//  Created by 伊藤 洋也 on 13/05/25.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
#include <sys/systm.h>
#include <libkern/libkern.h>
#include <mach/mach_types.h>

kern_return_t Sekigae_start(kmod_info_t * ki, void *d);
kern_return_t Sekigae_stop(kmod_info_t *ki, void *d);

kern_return_t Sekigae_start(kmod_info_t * ki, void *d)
{
    const char *newcomers[] = {
        "okkun",
        "keoken",
        "kitak",
        "gussan",
    };
    unsigned int members_count = sizeof(newcomers) / sizeof(char *);

    printf("Sekigae has started.\n");

    for (int i = 0; i < members_count; i++) {
        const char *swapped;
        int r;
        r = random() % members_count;
        swapped      = newcomers[r];
        newcomers[r] = newcomers[i];
        newcomers[i] = swapped;
    }

    for (int i = 0; i < members_count; i++) {
        printf("%s\n", newcomers[i]);
    }

    return KERN_SUCCESS;
}

kern_return_t Sekigae_stop(kmod_info_t *ki, void *d)
{
    printf("Sekigae has stopped.\n");
    return KERN_SUCCESS;
}
