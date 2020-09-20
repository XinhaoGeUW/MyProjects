package com.john.register;


import org.springframework.stereotype.Service;

import javax.transaction.Transactional;
import java.util.ArrayList;
import java.util.List;

@Service
@Transactional
public class UserService {
    private UserRepository repo;

    public void saveUser(User user) { repo.save(user); }

    public List<User> findAllUsers() {
        var it = repo.findAll();
        List<User> users = new ArrayList<>();
        it.forEach(user -> users.add(user));

        return users;
    }
    public UserService(UserRepository userRepository) { repo = userRepository; }

    public long countUsers() { return repo.count(); }

    public void deleteUser(long id) { repo.deleteById(id); }


}
