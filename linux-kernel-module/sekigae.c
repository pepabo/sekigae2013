#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/random.h>

MODULE_DESCRIPTION("Sekigae Module");
MODULE_AUTHOR("Sekigae");
MODULE_LICENSE("SUSHI");

static int sekigae_init_module(void)
{
        const char *newcomers[] = { 
                "okkun",
                "keoken",
                "kitak",
                "gussan",
        };  
        int i;
        unsigned int members_count = sizeof(newcomers) / sizeof(char *); 

        printk("sekigae module is loaded.\n");

        for (i = 0; i < members_count; i++) {
                char *swapped;
                unsigned int r;
                get_random_bytes(&r, sizeof r); 
                r = r % members_count;
                swapped      = newcomers[r];
                newcomers[r] = newcomers[i];
                newcomers[i] = swapped;
        }   

        for (i = 0; i < members_count; i++) {
                printk("%s\n", newcomers[i]);
        }   

        return 0;
}

static void sekigae_cleanup_module(void)
{
        printk("sekigae module is unloaded.\n");
}

module_init(sekigae_init_module);
module_exit(sekigae_cleanup_module);

