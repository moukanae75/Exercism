package cipher

import "strings"

type shift struct {
	distance int
}

type vigenere struct {
	key string
}

// Define the shift and vigenere types here.

// Both types should satisfy the Cipher interface.

func NewCaesar() Cipher {
	return NewShift(3)
}

func NewShift(distance int) Cipher {
	return &shift{distance: distance}
}

func (c shift) Encode(input string) string {
	var sb strings.Builder
	for _, r := range input {
		if r >= 'a' && r <= 'z' {
			sb.WriteByte(byte(((int(r-'a') + c.distance) % 26) + 'a'))
		} else if r >= 'A' && r <= 'Z' {
			sb.WriteByte(byte(((int(r-'A') + c.distance) % 26) + 'A'))
		} else {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

func (c shift) Decode(input string) string {
	var sb strings.Builder
	for _, r := range input {
		if r >= 'a' && r <= 'z' {
			sb.WriteByte(byte(((int(r-'a')-c.distance)%26+26)%26 + 'a'))
		} else if r >= 'A' && r <= 'Z' {
			sb.WriteByte(byte(((int(r-'A')-c.distance)%26+26)%26 + 'A'))
		} else {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

func NewVigenere(key string) Cipher {
    return &vigenere{key: key}
}

func (v vigenere) Encode(input string) string {
    var sb strings.Builder
    for i, r := range input {
        if r >= 'a' && r <= 'z' {
            key := int(v.key[i%len(v.key)] - 'a')
            sb.WriteByte(byte(((int(r-'a')+key)%26) + 'a'))
        } else if r >= 'A' && r <= 'Z' {
            key := int(v.key[i%len(v.key)] - 'A')
            sb.WriteByte(byte(((int(r-'A')+key)%26) + 'A'))
        } else {
            sb.WriteRune(r)
        }
    }
    return sb.String()
}

func (v vigenere) Decode(input string) string {
    var sb strings.Builder
    for i, r := range input {
        if r >= 'a' && r <= 'z' {
            key := int(v.key[i%len(v.key)] - 'a')
            sb.WriteByte(byte(((int(r-'a')-key)%26 + 26) % 26 + 'a'))
        } else if r >= 'A' && r <= 'Z' {
            key := int(v.key[i%len(v.key)] - 'A')
            sb.WriteByte(byte(((int(r-'A')-key)%26 + 26) % 26 + 'A'))
        } else {
            sb.WriteRune(r)
        }
    }
    return sb.String()
}
