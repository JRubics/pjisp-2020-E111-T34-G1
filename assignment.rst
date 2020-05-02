..
    Note for teaching assistants, you may find this introduction to reStructuredText useful:

    - https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/basics.html
    - https://www.sphinx-doc.org/en/1.8/usage/restructuredtext/directives.html#math



Prosečna visina drveta
======================

Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``drvo_st`` sastoji od sledećih polja:

- naziv drveta (jedna reč, do 20 karaktera)
- prosecna visina drveta u inch-ima (pozitivan ceo broj)

Na osnovu zadate jedinice (jedna reč, do 2 karaktera) i konverzije formirati novi
statički niz struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se
struktura ``visina_st`` sastoji od sledećih polja:

- naziv drveta (jedna reč, do 20 karaktera)
- prosecna visina (pozitivan realan broj)
- jedinica u kojoj je izražena visina (jedna reč, do 2 karaktera)

Nakon toga, u izlaznu datoteku ispisati naziv drveta koje ima najveću prosečnu visinu.

Primer poziva::

    ./a.out 0.0254 m drvo.txt visina.txt

sa ``konverzija=0.0254``, ``jedinica=m (1 inch = 0.0254 m)`` i zadatim ulazom u datoteci ``drvo.txt``::

    bukva     708
    kesten    1181
    bor       2362
    lipa      1181
    breza     1770
    hrast     985

i očekivanim izlazom u datoteci ``visina.txt``::

    bukva     17.98 m
    kesten    29.99 m
    bor       59.99 m
    lipa      29.99 m
    breza     44.95 m
    hrast     25.01 m

    Drvo sa najvecom prosecnom visinom je: bor
