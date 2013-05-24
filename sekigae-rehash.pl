use strict;
use warnings;

BEGIN {
    $SIG{__DIE__} = sub {
        CORE::die 'http://perldoc.jp/docs/perl/5.18.0/perl5180delta.pod#Hash32randomization';
    }
}
use v5.18.0;

my @name_list = ( "おっくん", "きたけー", "たけお", "ぐっさん" );

print join(", ", keys %{ {map {$_=>undef} @name_list} }),"\n";
