# EquivalentResistors

Simple program to find equivalent resistor configurations. Still in development.

## Options

-i desired resistance value

-r Resistor values omitted from search

-p minimum precision in percentage (default 5%)

## Example
`./REQ -i 2534 -r 2.4k 330 -p 10`

Outputs:

`
###########  
     •  
     |  
     |  
    |‾|  
    | |  
   750.00Ω  
    | |  
    |_|  
     |  
    |‾|  
    | |  
   1.80kΩ  
    | |  
    |_|  
     |  
     |  
     •       
###########  

2.70kΩ	 6.343%  
###########  
     •  
     |  
     |  
    |‾|  
    | |  
   2.70kΩ  
    | |  
    |_|  
     |  
     |  
     •  
###########\
`