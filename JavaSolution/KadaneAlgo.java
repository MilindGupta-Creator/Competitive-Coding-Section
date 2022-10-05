import java.util.ArrayList;

class KadaneAlgo {
        public static  int maxSubArray(int[] nums) {
            //arraylist is added to only store sequence it is not necessary ,code can run without it
            //visualise solution as train
            ArrayList<ArrayList<Integer>> li=new ArrayList<ArrayList<Integer>>();  //to store sequence 
            int sum=nums[0];
            li.add(new ArrayList<Integer>());
            li.get(0).add(nums[0]);
            int ci=0;
            int obest=sum;
            for(int i=1;i<nums.length;i++){
                if(sum+nums[i]>=nums[i]){
                    li.get(ci).add(nums[i]);
                    sum+=nums[i];
                    obest=Math.max(obest,sum);
                }
                else{
                    ci++;
                    li.add(new ArrayList<Integer>());
                    li.get(ci).add(nums[i]);
                    sum=nums[i];
                    obest=Math.max(obest,sum);
                }
            }
            System.out.println(li);
            return obest;
        }
    public static void main(String[] args) {
        int arr[]={3,1,-3,-4,-17,2,1,-5,4,6,-3,8,-15,87,-67};
        System.out.println(maxSubArray(arr));
    }    
}
