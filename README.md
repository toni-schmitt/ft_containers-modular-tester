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
<details>
    <summary>Show Description</summary>

1. Add a `.hpp` file under `tests/src/tests/[Container]` (`[Container]` being the Container you want to add a Test Case) (it is advised to follow the existing Naming Convention for your newly added `.hpp` file)
2. Copy the contents from `tests/src/tests/example_test.hpp` into your newly added `.hpp` file
3. Modify the copied content in your newly added `.hpp` file
    1. Modify `CONTAINER_NAME` to the Container (`[Container]`) you wanted to add a Test Case to 
        1. <b>Important:</b> `CONTAINER_NAME` has to be the same as `[Container]` (the Folder)
    2. Modify `TEST_CASE_NAME` to your Test Case Name (the Name does not have to be the same as the `.hpp` file, but it is advised to do so)
4. Add your own Tests
    1. Every Test works with log files, it is advised to write a lot of stuff into these log files
        1. You can write to the Log file with [`ofs`][1] and with the [`write::`][2] namespace defined in [`tests/src/utility/write.hpp`][3]

[1]: https://github.com/toni-schmitt/ft_containers-modular-tester/blob/main/tests/src/tests/i_base_test.hpp#L37
[2]: https://github.com/toni-schmitt/ft_containers-modular-tester/blob/main/tests/src/utility/write.hpp#L18-L118
[3]: https://github.com/toni-schmitt/ft_containers-modular-tester/blob/main/tests/src/utility/write.hpp
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

