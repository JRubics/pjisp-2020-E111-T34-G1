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

    bukva     712
    kesten    1192
    bor       2362
    lipa      1188
    breza     1770
    hrast     1000

i očekivanim izlazom u datoteci ``visina.txt``::

    bukva   18.1 m
    kesten  30.3 m
    bor     60.0 m
    lipa    30.2 m
    breza   45.0 m
    hrast   25.4 m

    Drvo sa najvecom prosecnom visinom je: bor

Visinu zaokružiti na jednu decimalu.