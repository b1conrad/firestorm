#!/usr/local/bin/perl -T

use Cwd;

print <<EOF;
Content-type: text/HTML

<html>
<head><title>Testing</title>
<body>
<pre>
Current directory is ${\getcwd()}
PERL version: $]
Real UID $<
Effective UID $>
Real GID $(
Effective GID $)
</pre>
EOF

print <<EOF;
<br>
<H2>\%ENV:</H2>
<table border>
EOF

while (($key,$val) = each %ENV) {
  print "<tr><td><strong>$key</strong></td><td>$val</td></tr>\n";
}

print  <<EOF;
</table>
</body></html>
EOF

print <<EOF;
<br>
<H2>\@ARGV:</H2>
<table border>
EOF

for (@ARGV) {
  print "<tr><td>$_</td></tr>\n";
}

print  <<EOF;
</table>
</body></html>
EOF

if (defined $ENV{'CONTENT_LENGTH'}) {
  read(STDIN, $buffer, $ENV{'CONTENT_LENGTH'});
  print  "<BR>$ENV{'CONTENT_LENGTH'} bytes from STDIN:<BR>\n<PRE>";
  print $buffer;
  print "</PRE><BR>"
}
