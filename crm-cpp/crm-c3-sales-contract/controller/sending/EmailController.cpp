#include "stdafx.h"
#include "EmailController.h"
#include "EmailSender.h"
#include <iostream>

EmailDTO::Wrapper EmailController::sendEmail(const EmailDTO::Wrapper& emailDto)
{
    const int smtp_port = 0;
    EmailSender emailSender("smtp_server", smtp_port, "password", "from_email", "from_name");

    // Set the email content.
    emailSender.setEmailContent(emailDto->subject, emailDto->message);

    for (size_t i = 0; i < (*emailDto->emailAddress).size(); ++i) {
        emailSender.addRecvEmailAddr(emailDto->emailAddress[i], emailDto->recipient_name[i]);
    }

    // Send the email.
    bool success = emailSender.send();

    // Check if the email was sent successfully.
    if (success) {
        std::cout << "Email sent successfully." << std::endl;
    }
    else {
        std::cout << "Failed to send email." << std::endl;
    }

    return emailDto;
}