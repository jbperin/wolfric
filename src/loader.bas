
5 PRINT@3,24;"Loading ..."

10 HIRES
;; 15 GET K$
;; 19 GET K$
20 POKE #BF68, 16: POKE #BF69, 7
30 POKE #BF90, 16: POKE #BF91, 7
40 POKE #BFB8, 16: POKE #BFB9, 7
70 POKE #BF70, ASC("L")
75 POKE #BF71, ASC("O")
80 POKE #BF72, ASC("A")
85 POKE #BF73, ASC("D")
90 POKE #BF74, ASC("I")
95 POKE #BF75, ASC("N")
100 POKE #BF76, ASC("G")
105 POKE #BF77, ASC(".")
110 POKE #BF78, ASC(".")
120 POKE #BF79, ASC(".")
200 CLOAD"
300 CLOAD"

