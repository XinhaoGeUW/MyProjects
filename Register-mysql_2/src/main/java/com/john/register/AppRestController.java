package com.john.register;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class AppRestController {
    @Autowired
    UserService service;

    @GetMapping("/")
    public String home() { return "Welcome to home page"; }

    @GetMapping("/users")
    public List<User> users() { return service.findAllUsers(); }

    @GetMapping("/users/count")
    public long count() { return service.countUsers(); }

    @GetMapping("/users/{id}")
    public void deleteUser(@PathVariable long id) { service.deleteUser(id); }

    @GetMapping("/save-user")
    public String saveUser(@RequestParam String username, @RequestParam String firstname, @RequestParam String lastname, @RequestParam int age, @RequestParam String password) {
        User user = new User(username, firstname, lastname, age, password);
        service.saveUser(user);
        return "Save User Successfully";
    }
}
