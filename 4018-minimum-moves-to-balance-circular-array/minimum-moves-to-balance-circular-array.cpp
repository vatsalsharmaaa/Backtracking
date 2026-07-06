class Solution {
public:
    typedef long long ll;

    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        ll sum=0;
        ll culpritidx=-1;

        for(int i=0;i<n;i++){
            if(balance[i]<0) culpritidx=i;
            sum+=balance[i];
        }
        if(sum<0) return -1;
        if(culpritidx==-1) return 0;
        int dist=1;
       ll moves=0;

        while(balance [culpritidx] < 0){
            ll left = (culpritidx - dist +n) % n;
            ll right= (culpritidx + dist) % n;

            ll available= balance[left] + balance[right];
            ll req =  abs( balance[culpritidx]);


            if(left==right){   //circular array h na
                available-=balance[right];
            }

            ll taken = min(available , req);
            balance[culpritidx]+=taken;
            moves+= dist * taken;
            dist ++;



        }
        return moves;

    }
};
















