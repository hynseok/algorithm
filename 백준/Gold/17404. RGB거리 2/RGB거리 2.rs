#![allow(unused_imports)]
#![allow(dead_code)]
use std::cmp::*;
use std::collections::*;
use std::io::*;
use std::fmt::Write;

struct Scanner {
  buffer: std::collections::VecDeque<String>
}
  
impl Scanner {
  fn new() -> Scanner {
    Scanner {
      buffer: std::collections::VecDeque::new()
    }
  }
 
  fn next<T : std::str::FromStr >(&mut self) -> T {
    if self.buffer.len() == 0 {
      let mut input = String::new();
      std::io::stdin().read_line(&mut input).ok();
      for word in input.split_whitespace() {
        self.buffer.push_back(word.to_string())
      }
    }

    let front = self.buffer.pop_front().unwrap();
    front.parse::<T>().ok().unwrap()
  }

  fn next_str(&mut self) -> String {
    if self.buffer.len() == 0 {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).ok();
        for word in input.split_whitespace() {
        self.buffer.push_back(word.to_string())
      }
    }
    self.buffer.pop_front().unwrap()
  }
}

struct Writer {
  output: String 
}

impl Writer {
  fn new() -> Writer {
    Writer {
      output: String::new()
    }
  }

  fn write(&mut self, str: String) {
      writeln!(self.output, "{}", str).unwrap();
  }

  fn print_out(&mut self) {
    println!("{}",self.output);
  }
}



fn main() {
  let MAX = 1000001;
  let mut ans = MAX;

  let mut cost: [[i32;3];1001] = [[0;3];1001];

  let mut s = Scanner::new();
  let mut w = Writer::new();

  let n:usize = s.next();
  for i in 1..n+1 {
    let (r, g, b):(i32, i32, i32) = (s.next(), s.next(), s.next());
    cost[i][0] = r;
    cost[i][1] = g;
    cost[i][2] = b;
  }

  for start in 0..3 {
    let mut dp: [[i32;3];1001] = [[0;3];1001];
    for i in 0..3 {
      if i == start {
          dp[1][start] = cost[1][start];
      } else {
          dp[1][i] = MAX;
      }
    }
    for i in 2..n+1 {
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
      dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + cost[i][2];
    }
    for i in 0..3 {
      if i == start {
        continue;
      }
      ans = min(ans, dp[n][i]);
    }
  }

  w.write(ans.to_string());
  w.print_out();
}
