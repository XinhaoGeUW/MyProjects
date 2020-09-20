package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import javax.ws.rs.POST;
import java.util.List;
import java.util.Optional;

@Controller
public class FormController {
    @Autowired
    CustomersRepo repo;

    @RequestMapping("/")
    public String john() {
        return "john";
    }

    @RequestMapping("/details")
    public String details(Customer cus) {
        repo.save(cus);
        return "john";
    }

    @RequestMapping("/get-details")
    public String getDetails() {
        return "viewcustomers";
    }

    @PostMapping("get-details")
    public ModelAndView getDetails(@RequestParam("id") int id) {
        ModelAndView mv = new ModelAndView("retrieve");
        Customer customer = repo.findById(id).orElse(null);
        mv.addObject(customer);
        return mv;
    }

    @RequestMapping("/customers")
    @ResponseBody
    public List<Customer> getCustomer() { return repo.findAll(); }

    @RequestMapping("/customers/{id}")
    @ResponseBody
    public Optional<Customer> getOneCustomer(@PathVariable("id") int id) {
        return repo.findById(id);
    }

    @PostMapping("/customers")
    public Customer postCustomer(@RequestBody Customer cus) {
        repo.save(cus);
        return cus;
    }

    @PutMapping(path="/customers", consumes={"application/json"}) // meaning it consumes/you need to insert json format
    public Customer putCustomer(@RequestBody Customer cus) {
        repo.save(cus);
        return cus;
    }

    @DeleteMapping("/customers/{id}")
    public Customer deleteCustomer(@PathVariable("id") int id) {
        Customer cus = repo.getOne(id);
        repo.delete(cus);
        return cus;
    }
}


/*
    create source => @PostMapping
    read source => @GetMapping
    upload source => @PutMapping
    delete source => @DeleteMapping

    Use REST API to manipulate data:
    1. pass data from web application to database or
    2. from database to web application and spring boot
 */
