package stringset

// Implement Set as a collection of unique string values.
//
// For Set.String, use '{' and '}', output elements as double-quoted strings
// safely escaped with Go syntax, and use a comma and a single space between
// elements. For example, a set with 2 elements, "a" and "b", should be formatted as {"a", "b"}.
// Format the empty set as {}.

// Define the Set type here.
type Set struct{
	arr []string
	
}

func New() Set {
	var s Set
	return s
}

func NewFromSlice(l []string) Set {
	var s Set
	s.arr = l
	return s
}

func (s Set) String() string {
	newstr := ""
	for i := 0; i < len(s.arr); i++ {
		newstr += s.arr[i]
	}
	return newstr
}

func (s Set) IsEmpty() bool {
	var empty int
	for i := 0; i < len(s.arr); i++ {
		empty++
	}
	return empty == 0 
}

func (s Set) Has(elem string) bool {
	for i := 0; i < len(s.str); i++ {
		if elem == s.str {
			return true
		}
	}
	return false
}

func (s Set) Add(elem string) {
	panic("Please implement the Add function")
}

func Subset(s1, s2 Set) bool {
	panic("Please implement the Subset function")
}

func Disjoint(s1, s2 Set) bool {
	panic("Please implement the Disjoint function")
}

func Equal(s1, s2 Set) bool {
	panic("Please implement the Equal function")
}

func Intersection(s1, s2 Set) Set {
	panic("Please implement the Intersection function")
}

func Difference(s1, s2 Set) Set {
	panic("Please implement the Difference function")
}

func Union(s1, s2 Set) Set {
	panic("Please implement the Union function")
}
