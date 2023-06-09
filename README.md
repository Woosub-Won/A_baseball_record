# 야구 기록지 작성 프로그램
이 프로그램은 야구 경기 결과를 기록하는 기능을 제공합니다. 사용자는 각 경기의 팀, 점수, 선수의 기록 등을 입력하여 야구 기록지를 작성할 수 있습니다.
<br><br>

# 주의사항
팀 이름 기입시 글자 두 글자로 제한됩니다.
<br>
Ex) 두산, 한화, 기아, 롯데 등
<br>
한국프로야구의 모든 팀은 두 글자로 표현 가능합니다.

# 설치
이 저장소를 클론하거나 다운로드합니다.
<br><br>

# 사용법
1. A Baseball record.exe 파일을 실행합니다.
2. 원정 팀 이름을 작성합니다.
3. 타자의 수를 입력하고, 그에 맞게 타자들을 입력합니다.
4. 투수의 수를 입력하고, 그에 맞게 투수들을 입력합니다.
5. 선발 라인업을 작성합니다.
6. 홈 팀 이름을 작성합니다.
7. 타자의 수를 입력하고, 그에 맞게 타자들을 입력합니다.
8. 투수의 수를 입력하고, 그에 맞게 투수들을 입력합니다.
9. 선발 라인업을 작성합니다.
10. 매 이닝, '타자[홈팀] vs 투수[원정팀]' 정보가 출력되고, 해당 타자 혹은 투수를 변경하고 싶다면 'Y'를 눌러 교체합니다.
11. 타자 및 투수가 확정되면, 투수가 던지는 매 공마다 Strike, Ball, Foul, Hit 4가지의 명령어로 기입을 합니다.
12. Hit가 입력되면 타자가 FB, GB, H1, H2, H3, HR, E 등의 정보를 추가로 입력을 합니다.
13. 3 out이 되면 자동으로 이닝이 교대되고 점수 및 안타, 에러, 볼넷의 개수가 전광판에 기록됩니다.
14. 승리 조건 혹은 무승부가 되면 경기가 종료됩니다.
<br><br>

![img1](./%EC%9B%90%EC%A0%95%ED%8C%80%20%EC%A0%95%EB%B3%B4%20%EA%B8%B0%EC%9E%85.png)
![img2](./%ED%99%88%ED%8C%80%20%EC%A0%95%EB%B3%B4%20%EA%B8%B0%EC%9E%85.png)
![img3](./%EA%B2%BD%EA%B8%B0%20%EC%A7%84%ED%96%89%20%EB%B0%8F%20%EC%84%A0%EC%88%98%20%EA%B5%90%EC%B2%B4.png)

# 예시
```
// 원정팀 정보 입력
한화이글스
14
문현빈 64 10
정은원 43 10
채은성 22 11
김인환 37 10
노시환 8 10
최재훈 13 10
장진혁 51 11
김건 97 10
이도윤 7 10
오선진 6 10
박정현 9 10
이원석 50 11
이진영 45 11
박상언 42 10
10
산체스 34
김기중 15
김범수 47
정우람 57
이태양 46 
윤대경 5
박상원 58
김서현 54
한승주 59
강재민 55
Y
문현빈 64 8
정은원 43 4
채은성 22 9
김인환 37 3
노시환 8 5
최재훈 13 2
장진혁 51 7
김건 97 0
이도윤 7 6
산체스 34 1

// 홈팀 정보 입력
두산베어스
14
문현빈 64 10
정은원 43 10
채은성 22 11
김인환 37 10
노시환 8 10
최재훈 13 10
장진혁 51 11
김건 97 10
이도윤 7 10
오선진 6 10
박정현 9 10
이원석 50 11
이진영 45 11
박상언 42 10
10
산체스 34
김기중 15
김범수 47
정우람 57
이태양 46 
윤대경 5
박상원 58
김서현 54
한승주 59
강재민 55
Y
문현빈 64 8
정은원 43 4
채은성 22 9
김인환 37 3
노시환 8 5
최재훈 13 2
장진혁 51 7
김건 97 0
이도윤 7 6
산체스 34 1

// 경기시작
N   // 선수 교체 x
S   // strike
B   // ball
H   // hit
H1  // 안타
...

```
<br><br>

# 기능
- 팀 이름 저장 가능
- 팀별 선수의 이름, 등번호, 포지션 저장 가능
- 팀별 선수들의 출전 여부 저장 가능
- 경기 중 선수들의 교체 여부 기입 가능
- 팀별 안타, 에러, 볼넷 수 기입 가능
- 경기 진행 상황을 전광판을 통해 파악 가능