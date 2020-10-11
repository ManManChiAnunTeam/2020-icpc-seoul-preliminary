#include <iostream>
#include <algorithm>
#include <climits>

typedef long long Long;

std::pair<Long, Long> polices[500000];
std::pair<Long, Long> theif;
int n;

bool isCaptured(std::pair<Long, Long> point, Long elapsed)
{
    bool result = false;
    for (int i = 0; i < n && !result; ++i)
    {
        result = point.second <= point.first + polices[i].second - polices[i].first + elapsed &&
                point.second <= -point.first + polices[i].second + polices[i].first + elapsed &&
                point.second >= point.first + polices[i].second - polices[i].first - elapsed &&
                point.second >= -point.first + polices[i].second + polices[i].first - elapsed;
    }
    return result;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", &polices[i].first, &polices[i].second);
    
    scanf("%lld %lld", &theif.first, &theif.second);

    Long e = INT32_MAX;
    if (isCaptured({theif.first + e, theif.second}, e) &&
        isCaptured({theif.first - e, theif.second}, e) &&
        isCaptured({theif.first, theif.second + e}, e) &&
        isCaptured({theif.first, theif.second - e}, e))
        printf("NO");
    else printf("YES");

    return 0;
}