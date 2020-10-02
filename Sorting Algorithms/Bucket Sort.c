void bucketSort(float[] a,int n)
{
    for(each floating integer 'x' in n)
    {
        insert x into bucket[n*x]; 
    }
    for(each bucket)
    {
        sort(bucket);
    }
}