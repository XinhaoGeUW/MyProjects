/*
package com.john.register;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;
import java.util.Optional;

@Controller
public class AppController {
    @Autowired
    UserRepository repo;

    @RequestMapping("/welcome")
    public String welcome() {
        return "welcome";
    }

    @RequestMapping("/userinfo")
    public String saveuser(User user) {
        repo.save(user);
        return "welcome";
    }

    @RequestMapping("/get-info")
    public String getDetails() {
        return "viewuser";
    }

    @PostMapping("get-info")
    public ModelAndView getDetails(@RequestParam("id") int id) {
        ModelAndView mv = new ModelAndView("retrieve");
        User user = repo.findById(id).orElse(null);
        mv.addObject(user);
        return mv;
    }

    @RequestMapping("/users")
    @ResponseBody
    public List<User> ShowAll() { return (List<User>) repo.findAll(); }

    @RequestMapping("/users/{id}")
    @ResponseBody
    public Optional<User> idCustomer(@PathVariable int id) { return repo.findById(id); }

    @PostMapping("/users")
    public void postUser(User user) { repo.save(user); }

    @PutMapping(path = "/users", consumes = {"application/json"}) // meaning it consumes/you need to insert json format
    public void putCustomer(@RequestBody User user) { repo.save(user); }

    @DeleteMapping("/users/{id}")
    public void deleteUser(@PathVariable int id) { repo.deleteById(id); }
}
*/
