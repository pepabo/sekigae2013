#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/random.h>

MODULE_DESCRIPTION("Sekigae Module");
MODULE_AUTHOR("Sekigae");
MODULE_LICENSE("SUSHI");

#define PROCFS_ENTRY "sekigae"

static struct proc_dir_entry *sekigae_proc_dir_entry = NULL;

static int
procfile_read(char *buffer,
          char **buffer_location,
          off_t offset, int buffer_length, int *eof, void *data)
{
    int ret = 0;
    int length = 0;
    int i;

    const char *newcomers[] = {
        "okkun",
        "keoken",
        "kitak",
        "gussan",
    };

    unsigned int members_count = sizeof(newcomers) / sizeof(char *);
    for (i = 0; i < members_count; i++) {
        const char *swapped;
        unsigned int r;
        get_random_bytes(&r, sizeof r);
        r = r % members_count;
        swapped      = newcomers[r];
        newcomers[r] = newcomers[i];
        newcomers[i] = swapped;
    }

    for (i = 0; i < members_count; i++) {
        length += sprintf(buffer + length, "%s\n", newcomers[i]);
    }

    if (length > buffer_length) {
      ret = -ENOMEM;
    } else {
      ret = length;
    }

    return ret;
}

static int sekigae_init_module(void)
{
    sekigae_proc_dir_entry = create_proc_entry(PROCFS_ENTRY, 0644, NULL);
    if( sekigae_proc_dir_entry == NULL ) {
        remove_proc_entry(PROCFS_ENTRY, NULL);
        printk(KERN_ALERT "Error: Could not initialize /proc/%s\n",
               PROCFS_ENTRY);
        return -ENOMEM;
    }

    sekigae_proc_dir_entry->read_proc = procfile_read;
    sekigae_proc_dir_entry->uid       = 0;
    sekigae_proc_dir_entry->gid       = 0;

    return 0;
}

static void sekigae_cleanup_module(void)
{
    remove_proc_entry(PROCFS_ENTRY, NULL);
    printk("sekigae module is unloaded.\n");
}

module_init(sekigae_init_module);
module_exit(sekigae_cleanup_module);
