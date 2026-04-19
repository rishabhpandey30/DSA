class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int dist=0;
        for (int i=0, j=0; i<n1 && j<n2; ) {
            const bool valid=(nums1[i]<=nums2[j]);
            const int inc=j-i-dist;
            dist+=(-(valid & (inc>0))) & inc;
            const bool moveJ=valid|(i>j);
            j+=moveJ;
            i+=!moveJ;
        }
        return dist;
    }
};