============
samCleanName
============
  
samCleanName is a C application which parsers sam files and removes @ character from read headers.

SAM files are read through standard input.

---------
Licensing
---------

samCleanName is licensed under GPL. See LICENSE for more information.

-----------
Compilation
-----------

1) For common usage compile the Release version:

    cd samCleanName/Release
    make clean
    make

A binary should be generated at Release folder called samCleanName.

2) For testing usage compile the Debug version:

    cd samCleanName/Debug
    make clean
    make

A debug binary should be created at Debug folder called samCleanName.


-------------
Documentation
-------------

samCleanName reads SAM input files directly from standard input.

Example:

    cat mySamFile.sam | samCleanName > mySamFile.cleaned.sam


------
Author
------

Marcos Fernandez-Callejo at (CNAG/CRG) Centre Nacional d’Anàlisi Genòmica / Centre de Regulació Genòmica.
marcos.fernandez@cnag.crg.eu

