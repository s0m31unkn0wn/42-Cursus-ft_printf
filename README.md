Easy to read, no malloc (so if francinette --strict finds leaks - well they aren't mine).

utils are called "modified" because, for one, they all return ints not voids, and putnbr is kind of put_hex_nbr really, which allows to write base-10 just by using only the first 10 "digits".

putptr is basically a copy of put_hex_nbr. Maybe you can drop it completely and just use the putnbr in small hex characters, but i decided not to, and the format selector in ft_printf.c would have been less obvious.
