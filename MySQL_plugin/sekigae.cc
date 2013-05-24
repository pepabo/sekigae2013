

#include <sql_class.h>
#include <table.h>

static struct st_mysql_information_schema sekigae_table_info=
{
  MYSQL_INFORMATION_SCHEMA_INTERFACE_VERSION
};

static ST_FIELD_INFO sekigae_fields[]=
{
  {"NAME", 10, MYSQL_TYPE_STRING, 0, 0, 0, 0}
};

static int sekigae (THD *thd, TABLE_LIST *tables, COND *cond)
{
  TABLE *table= tables->table;
  char *freshers[] = {"おっくん", "ぐっさん", "たけお", "きたけー"};
  int n, rnd;
  char *tmp = "";

  srand(time(NULL));
  for (n= 0; n < 4; n++){
    rnd = rand() % 4;
    tmp = freshers[n];
    freshers[n] = freshers[rnd];
    freshers[rnd] = tmp;
  }

  for (n= 0; n < 4; n++)
  {
    table->field[0]->store(freshers[n], strlen(freshers[n]), system_charset_info);
    table->file->ha_write_row(table->record[0]);
  }
}

static int sekigae_init (void *ptr)
{
  ST_SCHEMA_TABLE *schema_table= (ST_SCHEMA_TABLE*) ptr;

  schema_table->fields_info= sekigae_fields;
  schema_table->fill_table= sekigae;
  return 0;
}

mysql_declare_plugin (sekigae)
{
  MYSQL_INFORMATION_SCHEMA_PLUGIN,
  &sekigae_table_info,
  "sekigae",
  "yoku0825",
  "sekigae information_schema plugin",
  PLUGIN_LICENSE_GPL,
  sekigae_init,
  NULL,
  0x0100,
  NULL,
  NULL,
  NULL,
  0
}
mysql_declare_plugin_end;
