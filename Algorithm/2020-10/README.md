2020-10 ALGORITHM DIARY

### 10/04 [백준 12865 평범한 배낭](https://www.acmicpc.net/problem/12865)

이 문제는 아주 평범한 배낭에 관한 문제이다.

한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.

준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K무게까지의 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

- [BJ12865.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ12865.cpp)

    알고리즘 수업 때 배웠던 knapsack의 대표적인 문제인데 알고리즘이 기억이 잘 안나서 knapsack 알고리즘 대표 코드를 참고해서 풀었다.

### 10/04 [백준 5014 스타트링크](https://www.acmicpc.net/problem/5014)

강호는 코딩 교육을 하는 스타트업 [스타트링크](https://startlink.io/)에 지원했다. 오늘은 강호의 면접날이다. 하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.

스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다. 강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다. U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. (만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

- [BJ5014.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ5014.cpp)

    BFS를 사용해서 풀었다.

### 10/05 [백준 1158 요세푸스 문제](https://www.acmicpc.net/problem/1158)

요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

- [BJ1158.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ1158.cpp)

    Queue를 사용해서 풀었다.
    

### 10/07 [백준 14395 4연산](https://www.acmicpc.net/problem/14395)

정수 s가 주어진다. 정수 s의 값을 t로 바꾸는 최소 연산 횟수를 구하는 프로그램을 작성하시오.

사용할 수 있는 연산은 아래와 같다.

s = s + s; (출력: +)
s = s - s; (출력: -)
s = s * s; (출력: *)
s = s / s; (출력: /) (s가 0이 아닐때만 사용 가능)

- [BJ14395.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ14395.cpp)

    BFS 문제인데, 처음에 큐 초기화를 잘못해서 시간을 엄청 많이 잡아먹었다.
    

### 10/07 [백준 2805 나무 자르기](https://www.acmicpc.net/problem/2805)

상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.

목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다)

상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

- [BJ2805.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ2805.cpp)

    이분 탐색인데 처음의 left 값을 0 이 아니라 입력 값의 최소값으로 정해놓고 못 풀고 있었다.. 이분 탐색은 부등호, 브레이크 포인트, upper/lower bound 정하는게 너무 헷갈려서 어려운 것 같다..
    
### 10/13 [백준 17144 미세먼지 안녕! ](https://www.acmicpc.net/problem/17144)

미세먼지를 제거하기 위해 구사과는 공기청정기를 설치하려고 한다. 공기청정기의 성능을 테스트하기 위해 구사과는 집을 크기가 R×C인 격자판으로 나타냈고, 1×1 크기의 칸으로 나눴다. 구사과는 뛰어난 코딩 실력을 이용해 각 칸 (r, c)에 있는 미세먼지의 양을 실시간으로 모니터링하는 시스템을 개발했다. (r, c)는 r행 c열을 의미한다.
공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 공기청정기가 설치되어 있지 않은 칸에는 미세먼지가 있고, (r, c)에 있는 미세먼지의 양은 Ar,c이다.

1초 동안 아래 적힌 일이 순서대로 일어난다.

미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다.
(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.
위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

- [BJ17144.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ17144.cpp)

    복잡한 알고리즘 문제는 아니고 시키는대로 하는 문제인데 머리가 안돌아간다

### 10/14 [백준 2960 에라토스테네스의 체 ](https://www.acmicpc.net/problem/2960)
에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.

이 알고리즘은 다음과 같다.

2부터 N까지 모든 정수를 적는다.
아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
N, K가 주어졌을 때, K번째 지우는 수를 구하는 프로그램을 작성하시오.

- [BJ2960.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ2960.cpp)

    요즘 삼성 코딩테스트 준비하다가 조금 머리 식히고 싶어서 쉬운 문제를 풀었다 
    
    
### 10/15 [백준 15686 치킨 배달 ](https://www.acmicpc.net/problem/15686)
크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다. r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 도시의 치킨 거리는 모든 집의 치킨 거리의 합이다.

임의의 두 칸 (r1, c1)과 (r2, c2) 사이의 거리는 |r1-r2| + |c1-c2|로 구한다.

이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

- [BJ2960.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ15686.cpp)

    완전 탐색으로 풀었다
    
### 10/16 [백준 17822 원판 돌리기 ](https://www.acmicpc.net/problem/17822)
반지름이 1, 2, ..., N인 원판이 크기가 작아지는 순으로 바닥에 놓여있고, 원판의 중심은 모두 같다. 원판의 반지름이 i이면, 그 원판을 i번째 원판이라고 한다. 각각의 원판에는 M개의 정수가 적혀있고, i번째 원판에 적힌 j번째 수의 위치는 (i, j)로 표현한다. 수의 위치는 다음을 만족한다.

(i, 1)은 (i, 2), (i, M)과 인접하다.
(i, M)은 (i, M-1), (i, 1)과 인접하다.
(i, j)는 (i, j-1), (i, j+1)과 인접하다. (2 ≤ j ≤ M-1)
(1, j)는 (2, j)와 인접하다.
(N, j)는 (N-1, j)와 인접하다.
(i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1)
원판의 회전은 독립적으로 이루어진다. 2번 원판을 회전했을 때, 나머지 원판은 회전하지 않는다. 원판을 회전시킬 때는 수의 위치를 기준으로 하며, 회전시킨 후의 수의 위치는 회전시키기 전과 일치해야 한다.
원판을 아래와 같은 방법으로 총 T번 회전시키려고 한다. 원판의 회전 방법은 미리 정해져 있고, i번째 회전할때 사용하는 변수는 xi, di, ki이다.

번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.

- [BJ17822.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ17822.cpp)

    DFS, BFS, 시뮬레이션을 집중 공략.. 요즘 삼성 소프트웨어 사이트에서 문제를 푸는데,, 유출 금지라 업로드할 수는 없다    

### 10/17 [백준 14620 꽃길 ](https://www.acmicpc.net/problem/14620)
2017년 4월 5일 식목일을 맞이한 진아는 나무를 심는 대신 하이테크관 앞 화단에 꽃을 심어 등교할 때 마다 꽃길을 걷고 싶었다.

진아가 가진 꽃의 씨앗은 꽃을 심고나면 정확히 1년후에 꽃이 피므로 진아는 다음해 식목일 부터 꽃길을 걸을 수 있다.

하지만 진아에게는 꽃의 씨앗이 세개밖에 없었으므로 세 개의 꽃이 하나도 죽지 않고 1년후에 꽃잎이 만개하길 원한다.

꽃밭은 N*N의 격자 모양이고 진아는 씨앗을 (1,1)~(N,N)의 지점 중 한곳에 심을 수 있다. 꽃의 씨앗은 그림 (a)처럼 심어지며 1년 후 꽃이 피면 그림 (b)모양이 된다.
꽃을 심을 때는 주의할 점이있다. 어떤 씨앗이 꽃이 핀 뒤 다른 꽃잎(혹은 꽃술)과 닿게 될 경우 두 꽃 모두 죽어버린다. 또 화단 밖으로 꽃잎이 나가게 된다면 그 꽃은 죽어버리고 만다.
그림(c)는 세 꽃이 정상적으로 핀 모양이고 그림(d)는 두 꽃이 죽어버린 모양이다.

하이테크 앞 화단의 대여 가격은 격자의 한 점마다 다르기 때문에 진아는 서로 다른 세 씨앗을 모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다.

단 화단을 대여할 때는 꽃잎이 핀 모양을 기준으로 대여를 해야하므로 꽃 하나당 5평의 땅을 대여해야만 한다.

돈이 많지 않은 진아를 위하여 진아가 꽃을 심기 위해 필요한 최소비용을 구해주자!

- [BJ14620.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ14620.cpp)

    DFS, BFS, 시뮬레이션을 집중 공략..    
    
    
### 10/21 [백준 9655 돌 게임 ](https://www.acmicpc.net/problem/9655)
돌 게임은 두 명이서 즐기는 재밌는 게임이다.

탁자 위에 돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 돌은 1개 또는 3개 가져갈 수 있다. 마지막 돌을 가져가는 사람이 게임을 이기게 된다.

두 사람이 완벽하게 게임을 했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 먼저 시작한다.

- [BJ9655.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ9655.cpp)

    일요일에 이후로 머리 식히다가 간만에 문제를 하나 풀었다! DP 문제 랜덤으로 선택했는데 당황스러울정도로 쉬운 문제가 걸렸다
    
### 10/22 [백준 10026 적록색약 ](https://www.acmicpc.net/problem/10026)
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

- [BJ10026.py](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ10026.py)

    금요일에 파이썬으로 시험을 봐야 해서 익숙해지기 위해 쉬운 DFS 문제를 풀어 보았다,, 파이썬으로 DFS를 푸는건 처음인것같은데 sys.setrecursionlimit(100000) 를 넣어주지 않아서 런타임 에러가 났었다 대충푸느라 함수를 두개로 나누었는데 합쳐도 좋을 것 같다
    
### 10/22 [백준 1654 랜선 자르기 ](https://www.acmicpc.net/problem/1654)
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

- [BJ1654.py](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ1654.py)

    파이썬 입출력에 익숙해지기위한 문제~

### 10/22 [백준 11057 오르막 수 ](https://www.acmicpc.net/problem/11057)
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

- [BJ11057.py](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ11057.py)

    파이썬 입출력에 익숙해지기위한 문제~


### 10/29 [백준 2750 수 정렬하기 ](https://www.acmicpc.net/problem/2750)
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

- [BJ2750.cpp](https://github.com/Seulwoo/DailyStudy/blob/main/Algorithm/2020-10/BJ2750.cpp)

    c++ cin, cout 입출력에 익숙해지기 위해서 몸을 풀었다
