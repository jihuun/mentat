// https://velog.io/@soopsaram/Pramp-Drone-Flight-Planner
// https://www.pramp.com/question/BrLMj8M2dVUoY95A9x3X
// 
//
int calcDroneMinEnergy(size_t routeLength, int route[routeLength][3]) 
{
  int sum = 0;
  int prev = route[0][2];
  int min = 999999;

  for (int i = 1; i < routeLength; i++) {
    if (route[i][2] < prev) // prev 1
      sum += prev - route[i][2]; 
    else
      sum += prev - route[i][2]; 
    prev = route[i][2];
    if (sum < min)
      min = sum;
  }
  return min < 0? min * -1 : 0;
}

int main() {
  return 0;
}



/*
 *

FEEDBACK FOR YOUR PEER

Problem Solving: How were your peer's problem solving skills?
Question(s):Drone Flight Planner
' ' ' '
Amazing
Got an optimal solution with minimal guidance
Coding: How were your peer's coding skills?
' ' ' '
Strong
Works but not quite readable, reusable or maintainable
Communication: How were your peer's communication skills?
' ' ' '
Amazing
Every single bit was crystal clear
What did your peer do well during the session?
What are your peer's strengths? What impressed you?
- The process before starting coding was excellent
    - checking example/ discuss solutions / check complexity
- Talking about your thinking process during coding.
- Changing the solution idea from using a hashtable to linear search due to the inefficient space complexity.
- Solve the problem even if it is a complicated code flow.
- Easily found a bug or problem by yourself.
- No compile error when you finished a code.
What wasn't as good?
What should your peer improve? How would you advise them to get better?
- The code flow could be more simple (but I am impressed you can write code under complex code flow).
How did your peer perform as your interviewer?
Were they respectful and useful to you? Did they seem prepared to ask their question(s)?
' ' ' '
Great
Superb interviewer! Well done!
Give an appropriate hint at the right time with good examples due to your well understanding the question. I was nervous because of my lack of experience of coding interview. But you make the interview very comfortable. Thank you!



 */
