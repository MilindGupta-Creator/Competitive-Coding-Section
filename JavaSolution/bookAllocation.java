public class bookAllocation {
    public static void main(String[] args) {
        int[] arr= {6, 10, 5, 11, 7, 0, 1};
        int stu= 3;
        System.out.println(findRange(arr, stu));
    }
    static int findRange(int[] arr, int actualStu){
        int start= 0;
        int end= 0;
        for (int i = 0; i < arr.length; i++) {
            start= Math.max(start, arr[i]);
            end+= arr[i];
        }

        while (start<end){
            int sum= 0;
            int distributeStu= 1;

            int mid= start+(end-start)/2;
            for (int num: arr) {
                if(num + sum> mid){
                    sum= num;
                    distributeStu++;
                }
                else {
                    sum+= num;
                }
            }

            if(distributeStu>actualStu){
                start= mid+1;
            }else {
                end= mid;
            }
        }
        return end;
    }


}
