struct Box
{
    int l,w,h;
};

bool mycomp(Box b1,Box b2)
{
    return (b1.l * b1.w > b2.l*b2.w);
}

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
int maxHeight(int height[],int width[],int length[],int n)
{
    Box rotation[3*n];
    int idx = 0;
    for(int i=0;i<n;i++)
    {
        rotation[idx].h = height[i];
        rotation[idx].l = max(length[i],width[i]);
        rotation[idx].w = min(length[i],width[i]);
        
        idx++; 
        
        rotation[idx].h = length[i];
        rotation[idx].l = max(width[i],height[i]);
        rotation[idx].w = min(width[i],height[i]);
        
        idx++;
        
        rotation[idx].h = width[i];
        rotation[idx].l = max(length[i],height[i]);
        rotation[idx].w = min(length[i],height[i]);
        
        idx++;
    }
    sort(rotation,rotation+idx,mycomp);
    
    int dp[idx];
    dp[0] = rotation[0].h;
    int ans = dp[0];
    for(int i=1;i<idx;i++)
    {
        dp[i] = rotation[i].h;
        for(int j =0;j<i;j++)
        {
            if(rotation[i].l<rotation[j].l && rotation[i].w<rotation[j].w)
                dp[i] = max(dp[i],rotation[i].h+dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
