package com.demo.Spring_Security.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.web.authentication.logout.SecurityContextLogoutHandler;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class SpringSecurityController {

	@GetMapping("/")
	public String homePage(Model model)
	{
		model.addAttribute("title", "Spring Security : Authenciation and Authorisation");
		model.addAttribute("message", "Welcome to the Spring Security");
		return "index";
	}
	
	@GetMapping("/login")
	public String loginPage(
            @RequestParam(value="error", required = false)
            String error,
            @RequestParam(value="logout", required = false)
            String logout,
            Model model){

        if(error != null){
            model.addAttribute("error", "Invalid username and password");
        }

        if (logout !=null){
            model.addAttribute("msg", "You have been logged out successfully");
        }

        return "login";
    }
	
	@RequestMapping(value="/perform_logout", method = RequestMethod.GET)
	public String logoutPage (HttpServletRequest request, HttpServletResponse response) {
	    Authentication auth = SecurityContextHolder.getContext().getAuthentication();
	    if (auth != null){    
	        new SecurityContextLogoutHandler().logout(request, response, auth);
	    }
	    return "redirect:/";
	}

	@RequestMapping(value = "/user/home", method = RequestMethod.GET)
	public String userPage(Model model) {

		model.addAttribute("title", "User Logged In Successfull!!!");
		model.addAttribute("message", "Welcome User!");

		return "user";

	}

	@RequestMapping(value = "/admin/home", method = RequestMethod.GET)
	public String adminPage(Model model) {

		model.addAttribute("title", "Admin Logged In Successfull!!!");
		model.addAttribute("message", "You'r on a protected page of Admin!");

		return "admin";

	}
	
}

