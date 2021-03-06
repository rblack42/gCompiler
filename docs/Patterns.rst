C++ Codeing Patterns
####################

..  include::   /references.inc

This project is not designed as an end in itself. Instead, it is designed to
show how a relatively complex C++ project can be constructed by beginning C++
programmers. The idea is to demonstrate features of the language, and the
development environment used, so they can learn to better manage projects of
their own. The assumed skill level for this project is at least one full course
in C++, with a basic introduction to the class concepts.

Code Layout
***********

There are two primary directories for this project: **src** and **lib**. The
**src** directory contains only the *main.cpp* file, and any code needed to
interact with the user of the tool. This code is pretty generic, and can be
used in other projects with minor tweaks.

The **lib** directory is where all project class implementation files will be
found. Each class has a n accompanying test file, contained in the **tests**
directory. The class header file is stored in **include**. 

Building the Project
********************

This project is managed using a single **Makefile**, written for Gnu Make. The
code should build cleanly on any platform with a recent C++ compiler, if the
tool definitions in this **Makefile** are adjusted. The project was developed
using Gnu C++ on a Mac.

Continuous Integration
**********************

The source code for this project is available on GitHub_, and is tested using
Phil Nash's Catch_ unit testing system. As updates are pushed to GitHub_, the
project is tested by TravisCI_ to make sure al tests are passing. 

..  note::

    If the badge you see on the project README file is green, everything is
    working at that time. If the badge is read, I am probably working on the
    project.

Namespace Rules
***************

Most beginning C++ students are taught to use the **std** namespace without
giving much thought to why. In many modern C++ projects, you see this the line
any time I/O is required:

..  code-block:: c

    using namespace std;

This should not be done in header files, since it causes every name defined in
that **std** namespace to be included with the names being processed in the
current file. There are many names in there, and it might be quite possible
that they collide with names you have chosen. So, you should not just blindly
use that namespace line in your code. In this project, I will avoid the line,
and qualify each name from that space with the required **std::** prefix.

Basic Class Pattern
*******************

All classes defined for this project have clean header files, containing just
the method prototypes and attribute declarations. No code is included in these
headers. Header files are a contract between class implementers and class
users, and should not disclose details about how the class works. That pattern
makes it easier for the implementer to make improvements to the class, without
breaking user code.

All class constructors support a *debug* parameter, so the class can generate
output as objects are created, and methods are called. At present, a global
debug option is supported on the command line, activating the debug system in
every class, but this may change in the future.

..  vim:ft=rst spell:

