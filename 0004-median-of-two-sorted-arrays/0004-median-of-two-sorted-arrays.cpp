class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n1=nums1.size();
      int n2=nums2.size();
      int i=0;
      int j=0;
      int index2=(n1+n2)/2;
      int index1=index2-1;
      int count=0;
      int mid1=-1;
      int mid2=-1;
      while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(count==index1){
                mid1=nums1[i];
            }
            if(count==index2){
                mid2=nums1[i];
            }
            count++;
            i++;
        }
        else{
             if(count==index1){
                mid1=nums2[j];
            }
            if(count==index2){
                mid2=nums2[j];
            }
            count++;
            j++;
        }
      }
      while(i<n1){
            if(count==index1){
                mid1=nums1[i];
            }
            if(count==index2){
                mid2=nums1[i];
            }
            count++;
            i++;
      }
      while(j<n2){
        if(count==index1){
                mid1=nums2[j];
            }
            if(count==index2){
                mid2=nums2[j];
            }
            count++;
            j++;
      }  
      if((n1+n2) % 2==0){
        return (mid1+mid2)/2.00;
      }
      else{
        return mid2;
      }
    }
};