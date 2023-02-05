import "math/rand"

// Go
// leetcode 535
// https://leetcode.cn/problems/encode-and-decode-tinyurl/

type Codec struct {
	long2Tiny   map[string]string
	tiny2Long   map[string]string
	str, prefix string
	k, len      int
}

func Constructor() Codec {
	return Codec{
		long2Tiny: map[string]string{},
		tiny2Long: map[string]string{},
		str:       "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
		prefix:    "wxy",
		k:         6,
		len:       62,
	}
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	_, ok := this.long2Tiny[longUrl]
	for !ok {
		cs := make([]byte, this.k)
		for i := 0; i < this.k; i++ {
			cs[i] = this.str[rand.Intn(this.len)]
		}
		cur := this.prefix + string(cs)
		if _, existed := this.tiny2Long[cur]; existed {
			continue
		}
		this.long2Tiny[longUrl] = cur
		this.tiny2Long[cur] = longUrl
		ok = true
	}
	return this.long2Tiny[longUrl]
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	return this.tiny2Long[shortUrl]
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */