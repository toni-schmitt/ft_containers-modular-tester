# ft_containers-modular-tester

Yes another Tester for ft_containers! This one is written completely in C++98 and can be executed trough `make`

## How to Use
```
git clone https://github.com/toni-schmitt/ft_containers-modular-tester.git
```
1. Clone the tester into your ft_containers directory. 
    - If needed: Configure the Path to your .hpp files in the Makefile. (`make config` for help)
2. Print all available commands with `make help`
3. Test until everythig is Successful
    - Execute all tests with `make test`
    - Execute a single test with `make test C=container T=test` (for example: `make test C=vector T=modifiers` or `make test CONTAINER=vector TEST=modifiers`)
    - Execute all tests without Benchmarking with `make no_bench`

![usage3](https://user-images.githubusercontent.com/25370820/198146941-5b638c28-fc7d-4fcf-9e49-808e9699fb77.gif)
