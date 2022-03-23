/*
 * C++
 * leetcode 4
 * url: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * 奇数个只需要一个，偶数个需要两个
 * 不管如何，都用两个int 来装答案，如果是奇数个，那第二个 = 第一个
 * 用i，j当指针指向两个vector下一个待比较的index
 * get表示已经取的的小数字的个数
 * set t1部分用来设定第一个答案
 * set get部分用来设定第二个答案
 * 最后返回两数之和除以2.0
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size1 =nums1.size(), size2 = nums2.size();
    	int t1 = (size1+size2)/2, i =0, j =0, get = 0;
    	bool needSecond = false;
    	if((size1+size2)%2==0){
    		needSecond = true;
    		t1--;
    	}

    	while(get<t1){
    		if(i ==size1)
    			j++;
    		else if(j == size2)
    			i++;
    		else{
    			if(nums1[i] <nums2[j]){
    				i++;
    			}else{
    				j++;
    			}
    		}
    		get++;
    	}
    	// set t1
		if(i ==size1){
			t1 = nums2[j];
			j++;
		}else if(j == size2){
			t1 = nums1[i];
			i++;
		}else{
			if(nums1[i] <nums2[j]){
				t1 = nums1[i];
				i++;
			}else{
				t1 = nums2[j];
				j++;
			}
		}
		// set get
		if(!needSecond){
			get = t1;
		}else{
			if(i ==size1){
				get = nums2[j];
			}else if(j == size2){
				get = nums1[i];
			}else{
				if(nums1[i] <nums2[j]){
					get = nums1[i];
				}else{
					get = nums2[j];
				}
			}
		}

		return (t1+get)/2.0;
    }
};