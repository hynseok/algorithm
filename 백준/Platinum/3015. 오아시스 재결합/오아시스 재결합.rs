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
  let mut s: Scanner = Scanner::new();

  let n:u64 = s.next();
  let mut ans:u64 = 0;

  let mut stack: Vec<(u64, u64)> = Vec::new();

  let mut next = 0;
  let mut same = 0;
  for _i in 0..n {
    next = s.next();
    same = 1;

    while !stack.is_empty() && stack.last().unwrap().0 < next {
      ans += stack.last().unwrap().1;
      stack.pop();
    }

    if !stack.is_empty() {
      if stack.last().unwrap().0 == next {
        ans += stack.last().unwrap().1;
        same = stack.last().unwrap().1 + 1;
        if stack.len() > 1 {
          ans += 1;
        }
        stack.pop();
      } else {
        ans += 1;
      }
    } 

    stack.push((next, same));
  }

  println!("{}",ans.to_string());
}
