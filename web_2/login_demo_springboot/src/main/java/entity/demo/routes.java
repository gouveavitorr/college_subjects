package entity.demo;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class routes {

    @GetMapping("/")
    public String home(){
        return "login";
    }

}
