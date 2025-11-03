class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       //   for(int i=0;i<arr.size();i++){
    //     if(arr[i]<=k){
    //         k++;
    //     }
    //     else{
    //         break;
    //     }
    //   }
    //   return k;

    //less than O(n) tc
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        int missing= arr[mid]-(mid+1);
        if(missing<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }       
              //s=e+1;
    int ans = s+k; //ans= arr[e]+more; more=k-missing; missing=arr[e]-(e+1);
                   //ans= arr[e]+k-missing;
                   //ans= arr[e]+k-arr[e]+e+1;
                   //ans= k+e+1; where after loop e=s+1;
    return ans; 
    }
};