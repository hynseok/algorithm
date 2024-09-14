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
  let mut s = Scanner::new();
  let mut w = Writer::new();

  let mut n:usize = s.next();
  let mut k:usize = s.next();
  
  let mut j:Vec<(usize, usize)> = Vec::new();
  let mut b:Vec<usize> = Vec::new();
  let mut pq: BinaryHeap<usize> = BinaryHeap::new();
  let mut idx: usize = 0;
  let mut sum: usize = 0;

  for i in 0..n {
    let mut e1: usize = s.next();
    let mut e2: usize = s.next();
    j.push((e1, e2));
  }
  for j in 0..k{
    let mut e1: usize = s.next();
    b.push(e1);
  }
  j.sort();
  b.sort();
  
  for i in 0..k {
    while idx < n && b[i] >= j[idx].0 {
      pq.push(j[idx].1);
      idx+=1;
    }
    if !pq.is_empty() {
      sum += pq.peek().unwrap();
      pq.pop();
    }
  }

  w.write(sum.to_string());
  w.print_out();
}