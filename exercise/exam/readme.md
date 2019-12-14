# parse_string_and_calc.c

题目在这：

https://blog.csdn.net/Beyond_2016/article/details/82220196

parse_string_and_calc.c

解析类似这样的字符串，把"AB-1CD--2EF---3"数字和负号提取出来。计算所有数字的和。

简单。但是写的时候，还是考虑不全。debug才发现问题。

我的体会是，不要把问题复杂化。

我开始还想着把每个数字都记录下来，后面发现无此必要。要的只是和而已。

# perfect_len.cpp

这个是网易的题目。

是这个的前面一题。目前我只能通过80%的测试用例。

在长度为10000的用例上失败了。

https://www.nowcoder.com/question/next?pid=20791426&qid=800527&tid=29793749

我的解题思路不是很对。

有做对的，分析一下别人的思路。

```
1、首先，是输入一组，处理一组。
	没有必要全部输入完成再开始处理。
	看看别人处理输入是怎么做的。
	
```

```
int main()
{
	cin >> T;
	int arr[100005];//这个长度怎么来的。
	while(T--) {
		cin >> n;
		for(i=1;i<=n;i++) {
			cin >> arr[i];
		}
		//处理这一组。
		
	}
}
```

# eat_grape.cpp

吃葡萄。

这个关键在于发现数学上的规律。代码很简单。

关键就是这一行代码。

```
cout << max((sum + 2) / 3, (l[0] + 1) / 2) << endl;
```

# ask_salary.cpp

这个也很简单，但是题目讲得不太清楚。

关键就是map，来统计每个工资对应的人数。

# sum_half.cpp

这个从题目看，u64可以容纳下。最多10万个数字。

每个数字最大是10的10次方。

关键在于循环取数。也不是问题。如果有需要回绕的，那么一定是有一半是不需要回绕的。

```
#include <iostream>
#include <list>
using namespace std;

#define MAX_LEN 100000
int a[MAX_LEN];

void half_sum(int a[], int n)
{
    uint64_t sum = 0;
    for(int i=0; i<n; i++) {
        sum += a[i];
    }
    if(sum % 2) {
        cout << "NO" << endl;
        return;
    }
    uint64_t half ;
    int start = 0;
move_start:
    half = 0;
    for(int i=start; i<n-1; i++) {
        half += a[i];
        if(half == sum/2) {
            cout << "YES" << endl;
            return;
        } else if(half > sum/2) {
            start += 1;
            goto move_start;
        }
    }
    cout << "NO" << endl;
}
int main()
{
    int groups;
    cin >> groups;
    int n;
    while (groups--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        half_sum(a, n);
    }
}
```

这个算法复杂度不行，运行时间超过限制了。

```
您的代码已保存
运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
case通过率为60.00%
```

我就以这个例子来帮助分析吧。

```
1 1 4 1 1
4 1 1 1 1   这个情况，一上来就是符合要求的。
```



