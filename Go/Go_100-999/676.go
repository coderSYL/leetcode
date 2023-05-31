// Go
// leetcode 676
// https://leetcode.cn/problems/implement-magic-dictionary/

// 方法一，字典树
type TrieNode struct {
	Trie      [10009][26]int
	IsWordEnd [10009]bool
	Idx       int
}

func (t *TrieNode) insert(s string) {
	p := 0
	for _, c := range s {
		u := int(c - 'a')
		if t.Trie[p][u] == 0 {
			t.Idx++
			t.Trie[p][u] = t.Idx
		}
		p = t.Trie[p][u]
	}
	t.IsWordEnd[p] = true
}

func (t *TrieNode) searchP(s string, p, cur int, changed bool) bool {
	// 到了词尾，可以结算
	if cur == len(s) {
		return t.IsWordEnd[p] && changed
	}
	u := int(s[cur] - 'a')
	for i := 0; i < 26; i++ {
		if t.Trie[p][i] == 0 || (changed && i != u) { // 没机会选 i 的情况
			continue
		}
		if t.searchP(s, t.Trie[p][i], cur+1, changed || i != u) {
			return true
		}
	}

	return false
}

type MagicDictionary struct {
	tn *TrieNode
}

func Constructor() MagicDictionary {
	return MagicDictionary{&TrieNode{}}
}

func (this *MagicDictionary) BuildDict(dictionary []string) {
	for _, s := range dictionary {
		this.tn.insert(s)
	}
}

func (this *MagicDictionary) Search(searchWord string) bool {
	return this.tn.searchP(searchWord, 0, 0, false)
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dictionary);
 * param_2 := obj.Search(searchWord);
 */

//  // 方法二，map
//  type MagicDictionary struct {
//     Map map[int][]string
// }

// func Constructor() MagicDictionary {
//     return MagicDictionary{map[int][]string{}}
// }

// func (this *MagicDictionary) BuildDict(dictionary []string)  {
//     for _, d := range dictionary {
//         this.Map[len(d)] = append(this.Map[len(d)], d)
//     }
// }

// func (this *MagicDictionary) Search(searchWord string) bool {
//     out:
//     for _, d := range this.Map[len(searchWord)] {
//         cnt := 0
//         for i := 0; i < len(d); i++ {
//             if searchWord[i] != d[i] {
//                 cnt++
//             }
//             if cnt > 1 {
//                 continue out
//             }
//         }
//         if cnt == 1 {
//             return true
//         }
//     }
//     return false
// }

// /**
//  * Your MagicDictionary object will be instantiated and called as such:
//  * obj := Constructor();
//  * obj.BuildDict(dictionary);
//  * param_2 := obj.Search(searchWord);
//  */