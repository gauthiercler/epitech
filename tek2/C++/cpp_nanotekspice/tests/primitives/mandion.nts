# Admiral Business Machines 1954-2042
# Mandion is the contraction of "Mandatory" and "Option"

.chipsets:
input		a
input		b
input		c

output		s

4069		no
4071		or
4081		and

# (a)-|>o-|>o-[>=1]
# (b)-|>o-----[>=1]-|>o-[ & ]
# (c)-------------------[ & ]--<s>

.links:
# (a)-|>o-|>o-[>=1]
a:1		no:1
no:2		no:3
no:4		or:1

# (b)-|>o-----[>=1]
b:1		no:5
no:6		or:2

# [>=1]-|>o---[ & ]
# (c)---------[ & ]
or:3		no:9
no:8		and:1
c:1		and:2

# [ & ]-------<s>
s:1		and:3

