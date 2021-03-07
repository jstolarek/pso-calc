Phantasy Star Online Section ID Calculator
==========================================

This little utility computes a section ID assigned to player character in
Phantasy Star Online.  Section ID is calculated based on character's name and
determines one of ten guild the character is assigned to.  Each guild has
different drop rates for various weapons (see below) and different MAGs.


Usage
=====

To compute your section ID pass character's name as the argument:

```
$ pso-calc foobar
Section ID   : 3
Guild        : Bluefull
Good for     : Hunter
Common drops : Partisans (13%), Rods (10%)
Rare drops   : Wands (1%)
MAG type     : B
```

The result tells you which guild a character with this name will be assigned to,
what character class will work well with this name, which drops are the most
common, which are the most rare, and which class of MAGs to expect.  Note that
all character classes have a 13% drop chance for Sabers, Handguns, and Canes, so
these are not listed in the result.  Consult [this MAG
list](http://www.pso-world.com/sections.php?op=viewarticle&artid=1016) to
interpret the "MAG type" result.

Character name passed as argument can only contain ASCII characters and may be
at most 12 characters long.  If the name contains spaces wrap it in quotes like
this:

```
$ pso-calc "foo bar"
Section ID   : 5
Guild        : Pinkal
Good for     : Force
Common drops : Wands (13%), Partisans (10%)
Rare drops   : Rifles (1%)
MAG type     : B
```


Drop rates
==========

Below is a table with drop frequencies for all guilds (reproduced from
[here](http://www.pso-world.com/secprint.php?artid=452)).

| Section ID     | Sabers | Swords | Daggers | Partisans | Slicers | Handguns | Rifle  | Machineguns | Shotguns | Canes | Rods   | Wands  |
|----------------|--------|--------|---------|-----------|---------|----------|--------|-------------|----------|-------|--------|--------|
| **Viridia**    | 13     | 6      | 7       | **10**    | *1*     | 13       | 6      | 6           | **11**   | 13    | 7      | 7      |
| **Greennill**  | 13     | *1*    | **10**  | 6         | 6       | 13       | **13** | 7           | 4        | 13    | 7      | 7      |
| **Skyly**      | 13     | **13** | 7       | 6         | 6       | 13       | **10** | *1*         | 4        | 13    | 7      | 7      |
| **Bluefull**   | 13     | 7      | 6       | **13**    | 6       | 13       | 7      | 7           | 4        | 13    | **10** | *1*    |
| **Purplenum**  | 13     | 3      | **10**  | 3         | 6       | 13       | 7      | **13**      | 5        | 13    | 7      | 7      |
| **Pinkal**     | 13     | 6      | 7       | **10**    | 6       | 13       | *1*    | 7           | 4        | 13    | 7      | **13** |
| **Redria**     | 13     | 7      | *1*     | 7         | **10**  | 13       | 7      | 7           | 8        | 13    | 7      | 7      |
| **Oran**       | 13     | 8      | **13**  | 7         | 6       | 13       | 7      | 7           | 4        | 13    | *1*    | 8      |
| **Yellowboze** | 13     | 7      | 7       | 7         | 7       | 13       | 7      | 7           | 5        | 13    | 7      | 7      |
| **Whitill**    | 13     | 6      | 6       | 6         | **13**  | 13       | 6      | **10**      | *1*      | 13    | 7      | 6      |


Building from source
====================

The usual:

```
make
make install
```

The latter command requires root permissions.  There are no build dependencies
beyond C standard library.


Further reading
===============

I recommend taking a look at [Section ID guides at
pso-world.com](http://www.pso-world.com/sections.php?op=listarticles&secid=19),
and in particular [guild summary](http://www.pso-world.com/sections.php?op=viewarticle&artid=306),
[MAG list](http://www.pso-world.com/sections.php?op=viewarticle&artid=1016), and
[drop frequencies](http://www.pso-world.com/sections.php?op=viewarticle&artid=452).
