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

## How to add Test Case

Adding a Test Case is super easy, just follow these steps (I added 'insert_basic' Test Case to 'vector')
### 1. Add the Test Case (class)
<details>
    <summary>Show GIF</summary>

![clion_add_test_case_class](https://user-images.githubusercontent.com/25370820/198899713-70d72c33-9d0a-45ee-a0af-d95d19be13fc.gif)
</details>

### 2. Add a Test object
<details>
    <summary>Show GIF</summary>

![clion_add_test_case_test_object](https://user-images.githubusercontent.com/25370820/198899727-f23469fc-7d97-433d-bf84-457506c730a5.gif)
</details>

### 3. Add the Test Case to available_tests
<details>
    <summary>Show GIF</summary>

![clion_add_test_case_available_test](https://user-images.githubusercontent.com/25370820/198899758-f2356186-5551-470b-86fa-818c277b50e5.gif)
</details>

### 4. Run your newly added Test Case
<details>
    <summary>Show GIF</summary>

![clion_add_test_case_run](https://user-images.githubusercontent.com/25370820/198899780-4c56c56b-2927-4a5a-ab55-fc9b0c8c2859.gif)
</details>

