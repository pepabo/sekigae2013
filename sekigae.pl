use strict;
use List::Util;
 
my @name_list = ( "おっくん", "きたけー", "たけお", "ぐっさん" );
my @s_name_list = List::Util::shuffle @name_list;
 
print join(", ", @s_name_list);
