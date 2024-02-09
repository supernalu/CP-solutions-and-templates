use std::io;
use rand::Rng;
use std::cmp::Ordering;
fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=100);
    println!("Zgaduj zgadula!!!");
    loop {
             println!("Zgaduj baranku: ");
             let mut guess = String::new();
             io::stdin().read_line(&mut guess).expect("Failed to read line");
             let guess: u32 = guess.trim().parse().expect("to nie liczba cwoku");
             match guess.cmp(&secret_number) {
             Ordering::Less => println!("za malo hihi"),
             Ordering::Greater => println!("za duzo loool"),
             Ordering::Equal => {
                 println!("jooo ale szef!");
                 break;
             }
         }
    }

}
