package clock

import "fmt"

// Define the Clock type here.

type Clock struct {
	heur int
	minut int
	clok string
}

func New(h, m int) Clock {
	c := &Clock{heur: h,minut: m}

	if h < 0 {
		h *= -1
		h = h % 24
		c.heur =24 - h   
	}
	
	if m < 0 {
			c.minut = m

		for c.minut < 0 {
			c.minut += 60
			c.heur--
		}

		for c.heur < 0 {
			c.heur += 24
		}
	}
	
	
		for c.minut >= 60 {
			c.heur++
			c.minut -= 60
		}
		if c.heur >= 24 {
			c.heur = c.heur % 24
		}
	
	return *c
}

func (c Clock) Add(m int) Clock {
	c.minut += m
	if c.minut >= 60 {
		c.heur += c.minut /60
		c.minut = c.minut % 60
	}
	if c.heur >= 24 {
		c.heur = c.heur % 24
		
	}
	return c
}

func (c Clock) Subtract(m int) Clock {
    c.minut -= m

    for c.minut < 0 {
        c.minut += 60
        c.heur--
    }

    for c.heur < 0 {
        c.heur += 24
    }

    return c
}

func (c Clock) String() string {
	
	return fmt.Sprintf("%02d:%02d",c.heur,c.minut)
}
