int main()
{
    int arr[]{11,12,15,18,2,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
    {
        int key = arr[i];
        cout << searchElem(arr, n, key) << endl;
    }
    //cout << searchElem(arr, n, 11) << endl;
    
}