package kindergarten

import "strings"

// Define the Garden type here.
type Garden struct {
	diagram string
	children []string

}
// The diagram argument starts each row with a '\n'.  This allows Go's
// raw string literals to present diagrams in source code nicely as two
// rows flush left, for example,
//
//     diagram := `
//     VVCCGG
//     VVCCGG`

func NewGarden(diagram string, children []string) (*Garden, error) {
	return &Garden{diagram: diagram,children: children},nil
}

func (g *Garden) Plants(child string) ([]string, bool) {
	
	look := make(map[string]string)
	
		
	for i:=0;i<len(g.diagram)-1;i+=2 {
				if g.diagram[i] != '\n' {
					look[i:i+1] = g.children[i]
			}
	}
	

	
	
	
}
