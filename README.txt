MARCHIVO(1)                                                               User Commands                                                               MARCHIVO(1)



NAME
       mArchivo - format and print data

SYNOPSIS
       mArchivo FORMAT [ARGUMENT]...
       mArchivo OPTION

DESCRIPTION
       Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

       --help display this help and exit

       --version
              output version information and exit

       FORMAT controls the output as in C mArchivo.  Interpreted sequences are:

       \"     double quote

       \\     backslash

       \a     alert (BEL)

       \b     backspace

       \c     produce no further output

       \e     escape

       \f     form feed

       \n     new line

       \r     carriage return

       \t     horizontal tab

       \v     vertical tab

       \NNN   byte with octal value NNN (1 to 3 digits)

       \xHH   byte with hexadecimal value HH (1 to 2 digits)

       \uHHHH Unicode (ISO/IEC 10646) character with hex value HHHH (4 digits)

       \UHHHHHHHH
              Unicode character with hex value HHHHHHHH (8 digits)

       %%     a single %

       %b     ARGUMENT as a string with '\' escapes interpreted, except that octal escapes are of the form \0 or \0NNN

       and all C format specifications ending with one of diouxXfeEgGcs, with ARGUMENTs converted to proper type first.  Variable widths are handled.

       NOTE:  your shell may have its own version of mArchivo, which usually supersedes the version described here.  Please refer to your shell's documentation
       for details about the options it supports.

AUTHOR
       Written by David MacKenzie.

REPORTING BUGS
       Report mArchivo bugs to bug-coreutils@gnu.org
       GNU coreutils home page: <http://www.gnu.org/software/coreutils/>
       General help using GNU software: <http://www.gnu.org/gethelp/>
       Report mArchivo translation bugs to <http://translationproject.org/team/>

COPYRIGHT
       Copyright © 2013 Free Software Foundation, Inc.  License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

SEE ALSO
       mArchivo(3)

       The full documentation for mArchivo is maintained as a Texinfo manual.  If the info and mArchivo programs are properly installed at your site, the command

              info coreutils 'mArchivo invocation'

       should give you access to the complete manual.



GNU coreutils 8.21                                                       January 2015                                                               MARCHIVO(1)
