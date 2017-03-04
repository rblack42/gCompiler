Compiler Class Design
#####################

The top of the **gCompiler** class structure is the **Compiler** class. This
object will be created by an application for the purpose of processing a user
supplied source code string. That string will either come from a file on the
host system, of from a string supplied to the constructor. The later option is
used in testing extensively. 

Since it is not possible to tell the difference between a string holding a file
name and one holding actual source code, the constructor for this class will
need to handle both options. This is done by checking the size of the
**file_name** parameter. If it is zero, the assumption is that the constructor
is to build a string processor using the **code** parameter. Otherwise a file
with the specified name is read from the host.

In either case, the source code will be copied into a private buffer variable,
**source_code**, and the length of that string registered in **size**. All
other compiler code will access this buffer using pointers to the string object
to limit copying if the buffer gets large.

..  literalinclude:: /include/Compiler.h
    :linenos:
    :caption: Compiler.h

..  vim:ft=rst spell:
