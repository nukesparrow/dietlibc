#!/usr/bin/perl

our $def = "dietfeatures_default.h";

close STDIN;
open STDIN,"<",$def or die $def;
binmode STDIN;

my @lines = <STDIN>;

my %featues;
my $n=0;

foreach my $l (@lines) {
    if ($l =~ /#define\s+(\S+)/) {
        $features{$1} = $n;
    };
    $n++;
}

close STDIN;

#foreach my $f (keys(%features)) {
#    print "$f: " . $lines[$features{$f}];
#}

foreach my $arg (@ARGV) {
    my ($t,$n) = $arg =~ /^([-+])?(.+)/;
    $t = "+" if $t eq "";

    die "$n: no such feature" unless exists $features{$n};

    #print "$t : $n\n";

    if ($t eq "+") {
        $lines[$features{$n}] = "#define $n\n";
    } else {
        $lines[$features{$n}] = "/* #define $n */\n";
    }

    #print "n : $lines[$features{$n}]\n";

}

print join("",@lines);
